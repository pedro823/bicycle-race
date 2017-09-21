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
#ifndef __REPORTER_H__
#define __REPORTER_H__

/**
 * Sets the tick of the race to be amount ms
 * @param amount how many milliseconds each tick will have
 */
void set_tick(unsigned int amount);

/**
 * Gets the race tick.
 * @return The race tick set by set_tick
 */
unsigned int tick();

/**
 * Initializes the parameters for the race
 * @param d The length, in meters, of the velodrome
 * @param v the amount of laps the race will have
 * @param n the amount of cyclists the race will have
 */
void set_parameters(int d, int v, int n);

/**
 * Marks a lap as completed for the cyclist
 * @param id       The ID of the cyclist
 * @param position The position of the cyclist in the race
 * @param time     The time (in float, in seconds)
 *                 That the cyclist reached the lap line
 */
void lap_complete(int id, int lap, int position, float time);

#endif
