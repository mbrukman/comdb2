#ifndef _VIEWS_CRON_H_
#define _VIEWS_CRON_H_

#include  "comdb2uuid.h"

/**
 * Primitive cron job that monitors a ordered list of epoch marked events,
 * each having a callback function associated
 * Sleep until next event is to be triggered
 *
 */

/* opaque schedule */
typedef struct cron_sched cron_sched_t;

/* this is the callback prototype */
typedef void *(*FCRON)(uuid_t source_id, void *arg1, void *arg2, void *arg3, 
                       struct errstat *err);

/**
 * Add a new event to a scheduler.
 * Create a scheduler if none exists yet
 *
 */
cron_sched_t *cron_add_event(cron_sched_t *sched, const char *name, int epoch,
                             FCRON func, void *arg1, void *arg2, void *arg3,
                             uuid_t *source_id, struct errstat *err);

/**
 * Signal looping worker, maybe db is exiting
 *
 */
void cron_signal_worker(cron_sched_t *sched);

#endif

