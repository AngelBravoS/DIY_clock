/*
 * alarm.c
 */
#include "alarm.h"

/*
 * alarm_counter: used only within this module.
 * Must be reset to 0 by alarm_buzzer_on() before starting a new alarm.
 * Declared non-static so alarm.h can expose it to alarm_buzzer_on() if
 * that function is implemented as a macro. Encapsulate fully once
 * alarm_buzzer_on() becomes a regular function.
 */
volatile uint16_t alarm_counter;
volatile uint8_t  alarm_bp = 1;

/*!
 * \brief Descriptor de un patrón de pitido.
 *
 * El slot (pitido + pausa) es potencia de 2, lo que permite evaluar
 * la posición dentro del ciclo en la ISR con desplazamiento y AND
 * en lugar de división y módulo:
 *
 *   pitido activo  si:  (tick >> ALARM_SLOT_SHIFT) < n_beeps
 *                  y:   (tick &  ALARM_SLOT_MASK)  < beep_dur
 *
 * A 30 Hz: slot = 16 ticks (~533 ms por ranura).
 * Añadir un patrón nuevo solo requiere una entrada más en alarm_patterns[].
 */
typedef struct {
    uint8_t n_beeps;  ///< Número de pitidos por ciclo
    uint8_t beep_dur; ///< Duración del pitido en ticks (30 Hz)
    uint8_t cycle;    ///< Duración total del ciclo en ticks
} alarm_pattern_t;

/*!
 * \def ALARM_SLOT_SHIFT
 * log2 del slot (potencia de 2). tick >> ALARM_SLOT_SHIFT da el índice
 * del pitido actual dentro del ciclo.
 */
#define ALARM_SLOT_SHIFT  4

/*!
 * \def ALARM_SLOT_MASK
 * Máscara del slot (slot - 1). tick & ALARM_SLOT_MASK da la fase dentro
 * del pitido/pausa actual.
 */
#define ALARM_SLOT_MASK  15

/*!
 * \def ALARM_BEEP_DUR
 * Duración del pitido en ticks (~400 ms a 30 Hz).
 * Debe ser menor que el slot (16 ticks).
 */
#define ALARM_BEEP_DUR   12

/*!
 * \def ALARM_CYCLE
 * Duración total del ciclo en ticks (~3.2 s a 30 Hz).
 * Debe ser >= n_beeps_max * slot = 3 * 16 = 48.
 */
#define ALARM_CYCLE      96

/*
 * Tabla de patrones de alarma almacenada en flash (__code).
 * bP1: pitido único  —  bP2: doble pitido  —  bP3: triple pitido
 *
 * Tiempos resultantes (30 Hz → 1 tick ≈ 33 ms):
 *   Pitido:  12 ticks (~400 ms)
 *   Pausa:    4 ticks (~133 ms)
 *   Ciclo:   96 ticks (~3.2 s)
 */
__code static const alarm_pattern_t alarm_patterns[3] = {
    {1, ALARM_BEEP_DUR, ALARM_CYCLE},  /* bP1: un pitido */
    {2, ALARM_BEEP_DUR, ALARM_CYCLE},  /* bP2: dos pitidos  */
    {3, ALARM_BEEP_DUR, ALARM_CYCLE},  /* bP3: tres pitidos */
};

void ISR_T2() __interrupt(INT_T2) __using(0) {
    static uint8_t cnt  = 15;  ///< Tono: 8/15 ticks activo dentro del pitido
    static uint8_t tick = 0;   ///< Posición en el ciclo del patrón (30 Hz)
    __code const alarm_pattern_t *p;
    uint8_t bp;

    /*
     * Early exit: alarma expirada. Silenciar y mantener cnt para no
     * perder fase cuando vuelva a activarse.
     */
    if(alarm_counter >= ALARM_MAX_TIME) {
        ALARM_BUZZER_DRIVE_INACTIVE();
        if((--cnt) == 0) cnt = 15;
        return;
    }

    /* Seleccionar patrón; clamp defensivo por si alarm_bp llegara corrupto. */
    bp = alarm_bp;
    if(bp < 1 || bp > 3) bp = 1;
    p = &alarm_patterns[bp - 1];

    /*
     * tick >> ALARM_SLOT_SHIFT : índice del pitido actual (0, 1, 2…)
     * tick &  ALARM_SLOT_MASK  : fase dentro del slot (0…15)
     * cnt > 7                  : primera mitad del prescaler de tono
     */
    if(((tick >> ALARM_SLOT_SHIFT) < p->n_beeps) &&
       ((tick &  ALARM_SLOT_MASK)  < p->beep_dur) &&
       (cnt > 7))
        ALARM_BUZZER_DRIVE_ACTIVE();
    else
        ALARM_BUZZER_DRIVE_INACTIVE();

    if((--cnt) == 0) cnt = 15;
    if(++tick >= p->cycle) tick = 0;
    alarm_counter++;
}
