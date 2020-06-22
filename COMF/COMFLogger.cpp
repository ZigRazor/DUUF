/*
 * COMFLogger.cpp
 *
 *  Created on: 16 giu 2020
 *      Author: matteo
 */

#include "COMFLogger.h"

#include "log4cxx/basicconfigurator.h"
#include "log4cxx/propertyconfigurator.h"
#include "log4cxx/helpers/properties.h"

namespace DUUF {
namespace COMF {

COMF_Logger::COMF_Logger() {
    logger = log4cxx::Logger::getLogger("COMF");
    log4cxx::helpers::Properties property;
    property.setProperty("log4j.rootLogger", "TRACE, A1");
    property.setProperty("log4j.appender.A1", "org.apache.log4j.RollingFileAppender");
    property.setProperty("log4j.appender.A1.File", "COMF.log");
    property.setProperty("log4j.appender.A1.MaxFileSize", "100KB");
    property.setProperty("log4j.appender.A1.MaxBackupIndex", "10");
    property.setProperty("log4j.appender.A1.layout", "org.apache.log4j.PatternLayout");
    property.setProperty("log4j.appender.A1.layout.ConversionPattern", "%c - %-5p - %d{dd MMM yyyy HH:mm:ss,SSS} - [%t] (%F:%L) [%C::%M] %m%n");
    log4cxx::PropertyConfigurator::configure(property);
}

COMF_Logger::~COMF_Logger() {
}

log4cxx::LoggerPtr& COMF_Logger::getLogger() {
    static COMF_Logger instance;
    return instance.logger;
}

} /* namespace COMF */
} /* namespace DUUF */
