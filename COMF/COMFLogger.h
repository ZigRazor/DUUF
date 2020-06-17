/*
 * COMFLogger.h
 *
 *  Created on: 16 giu 2020
 *      Author: matteo
 */

#ifndef COMF_COMFLOGGER_H_
#define COMF_COMFLOGGER_H_

#include "log4cxx/logger.h"

namespace DUUF {
namespace COMF {

/*
 *
 */
class COMF_Logger {
public:
//    typedef enum Log_Level_E {
//        TRACE,
//        DEBUG,
//        INFO,
//        WARN,
//        ERROR,
//        FATAL
//    } Log_Level;
    static log4cxx::LoggerPtr& getLogger();
    virtual ~COMF_Logger();
    COMF_Logger( const COMF_Logger& other ) = delete;
    void operator=( COMF_Logger const& ) = delete;

    //void log( Log_Level level, const char* message );

private:
    COMF_Logger();
    log4cxx::LoggerPtr logger;
    static COMF_Logger instance;
};

} /* namespace COMF */
} /* namespace DUUF */

#endif /* COMF_COMFLOGGER_H_ */
