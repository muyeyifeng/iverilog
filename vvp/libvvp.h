#ifndef _LIBVVP_H_
#define _LIBVVP_H_

/* Interface definitions for libvvp.so.
 *
 * The main functions are vvp_init() and vvp_run() and they must be called
 * in that order.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/* vvp_set_stop_is_finish(true, 0) is equivalent to vvp's "-n" option.
 * vvp_set_stop_is_finish(true, 1) is equivalent to vvp's "-N" option.
 *
 * This function may be called at any time.
 */

extern void vvp_set_stop_is_finish(bool flag, int exit_code);

/* vvp_set_quiet_flag(true) is equivalent to vvp's "-q" option.
 *
 * This function may be called at any time.
 */

extern void vvp_set_quiet_flag(bool flag);

/* vvp_set_verbose(true) is equivalent to vvp's "-v" option.
 *
 * This function may be called at any time.
 */

extern void vvp_set_verbose_flag(bool flag);

/* vvp_no_signals() may be called at any time before vvp_run() to prevent
 * libvvp from handling signals generated by a terminal. It is recommended.
 */

extern void vvp_no_signals(void);

/* vvp_init() initialises the simulator.  The logfile_name argument is
 * the path to a file to receive logging output from the simulation.
 * It is equivalent to vvp's "-l" option, and may be NULL.
 * The argc argument is the size of the string array argv. These strings
 * are available to the simulation like additional non-option arguments
 * to vvp.
 *
 * The effect of calling vvp_init() for a second time is undefined unless
 * the library is first unloaded and reloaded.
 */

extern void vvp_init(const char *logfile_name, int argc, char*argv[]);

/* vvp_run() starts the simulation and returns the exit status
 * when it is complete. The argument is the path to a VVP file containing
 * compiled Verilog code.
 */

extern int vvp_run(const char *design_path);

/* vpip_load_module(module_name) may be called after vvp_init() and before
 * vvp_run() to load and initialise a VPI module. It is equivalent to
 * vvp's "-m" option.  If the module_name contains a directory separator
 * it is assumed to be the path to a VPI file, otherwise
 * it is searched for in directories on the current search path.
 */

extern void vpip_load_module(const char*name);

/* vpip_add_module_path() and vpip_clear_module_paths() may be called
 * after vvp_init() and  before vpip_load_module() to manipulate
 * the search path for VPI modules.  They are equivalent to vvp's "-M" option.
 * Some default paths are set by vvp_init().
 */

extern void vpip_add_module_path(const char*path);
extern void vpip_clear_module_paths(void);

#ifdef __cplusplus
}
#endif
#endif // _LIBVVP_H_
