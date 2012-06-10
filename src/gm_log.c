/*
 * gm_log.c
 * Copyright (C) Kevin DeKorte 2012 <kdekorte@gmail.com> and Hans Ecke
 * 
 * gm_log.c is free software.
 * 
 * You may redistribute it and/or modify it under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 * 
 * gm_log.c is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with playlist.c.  If not, write to:
 * 	The Free Software Foundation, Inc.,
 * 	51 Franklin Street, Fifth Floor
 * 	Boston, MA  02110-1301, USA.
 */  
    
#include "gm_log.h"
    
/* How to control the GLib logging system: with environment variables

G_MESSAGES_PREFIXED.  A list of log levels for which messages should be prefixed by the
program name and PID of the application. The default is to prefix everything except
G_LOG_LEVEL_MESSAGE and G_LOG_LEVEL_INFO. The possible values are error, warning, critical,
message, info and debug. You can also use the special values all and help.

G_MESSAGES_PREFIXED="" disables all prefixing

G_MESSAGES_DEBUG. Since glib 2.31, but emulated below for earlier versions.
A space-separated list of log domains for which informational and
debug messages should be printed. By default, these messages are not printed.

G_MESSAGES_DEBUG=GMTK enables a lot of output from gmtk

*/ 
    
#include <string.h>
    
#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN            ((gchar*) "GMLIB")

{
    
        // by default, all messages G_LOG_LEVEL_MESSAGE or above are shown
        // if our own debug flag is set, force G_LOG_LEVEL_INFO messages to MESSAGE
        //
        // GLib loglevels are bitmasks, so we need to do bitmask operations here
        if (force_info_to_message && ((*log_level) & G_LOG_LEVEL_INFO)) {
        (*log_level) &= ~G_LOG_LEVEL_INFO;
        (*log_level) |= G_LOG_LEVEL_MESSAGE;
    }
    
        // emulate G_MESSAGES_DEBUG for glib < 2.31
#if GLIB_MAJOR_VERSION == 2
#if GLIB_MINOR_VERSION < 31
        if ((*log_level) & G_LOG_LEVEL_DEBUG) {
        
        
            // if it doesn't exists or we can't find the string "GMLIB",
            // then don't print this message
            if (G_MESSAGES_DEBUG == NULL) {
            return 0;
        }
        
            return 0;
        }
        
            // this is not quite proper, but for a simple emulation whose need will go away in the future...
            if (strstr(G_MESSAGES_DEBUG, G_LOG_DOMAIN) == NULL && strstr(G_MESSAGES_DEBUG, "all") == NULL) {
            return 0;
        }
    
#endif
#endif
    return 1;
}


// Note that the format should not have a trailing \n - the glib logging system adds it
void gm_logv(gboolean force_info_to_message, GLogLevelFlags log_level, const gchar * format, va_list args)
{
    
        return;
    }
    
    



{
    
    va_start(args, format);
    gm_logv(force_info_to_message, log_level, format, args);
    va_end(args);

{
    gchar *msg_nonl = NULL;
    
        return;
    }
    
        // this function should be called if there might be a newline
        // at the end of the string. it will only allocate a copy
        // if necessary.
        size_t len = strlen(msg);
    
        g_log(G_LOG_DOMAIN, log_level, "%s", msg);
        return;
    }
    
    msg_nonl[len - 1] = '\0';
    g_log(G_LOG_DOMAIN, log_level, "%s", msg_nonl);
    g_free(msg_nonl);



{
    size_t len;
    gchar *msg_nonl = NULL;
    
        return;
    }
    
        // this function should be called if there might be a newline
        // at the end of the string. it will only allocate a copy
        // if necessary.
        len = strlen(msg);
    
        g_log(G_LOG_DOMAIN, log_level, "%s %s", prefix, msg);
        return;
    }
    
    msg_nonl[len - 1] = '\0';
    g_log(G_LOG_DOMAIN, log_level, "%s %s", prefix, msg_nonl);
    g_free(msg_nonl);
}