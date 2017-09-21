/******************************************************************************
 *                                                                            *
 *                   MAC0422 - Sistemas Operacionais - EP1                    *
 *                                                                            *
 *                          Prints reports on screen                          *
 *                                                                            *
 *                      Pedro Pereira     - NUSP 9778794                      *
 *                      Raphael R. Gusmao - NUSP 9778561                      *
 *                                                                            *
 ******************************************************************************/

static unsigned int tick;


void set_tick(unsigned int amount) {
    tick = amount;
}

unsigned int tick() {
    return tick;
}
