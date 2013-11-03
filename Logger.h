/*
 * Logger.h
 *
 *  Created on: 2011-01-17
 *      Author: jarrett
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace logger = boost::log;
namespace sinks = boost::log::sinks;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

using namespace logger::trivial;

#ifndef DEBUG
#define LOG_INFO(x)
#define LOG_DEBUG(x)
#define LOG_WARN(x)
#define LOG_ERROR(x)
#define LOG_FATAL(x)
#else
#define LOG_INFO(x)\
{\
	std::stringstream msg;\
	msg << x;\
	cs_logger::Logger::getInstance()->logInfo( msg.str() );\
}
#define LOG_DEBUG(x)\
{\
	std::stringstream msg;\
	msg << x;\
	cs_logger::Logger::getInstance()->logDebug( msg.str() );\
}
#define LOG_WARN(x)\
{\
	std::stringstream msg;\
	msg << x;\
	cs_logger::Logger::getInstance()->logWarn( msg.str() );\
}
#define LOG_ERROR(x)\
{\
	std::stringstream msg;\
	msg << x;\
	cs_logger::Logger::getInstance()->logError( msg.str() );\
}
#define LOG_FATAL(x)\
{\
	std::stringstream msg;\
	msg << x;\
	cs_logger::Logger::getInstance()->logFatal( msg.str() );\
}
#endif

namespace cs_logger {
class Logger {
	
public:
	static Logger* getInstance(std::string logFile = "default.log");
	
	void logInfo(std::string message);
	void logDebug(std::string message);
	void logWarn(std::string message);
	void logError(std::string message);
	void logFatal(std::string message);
	
	void logInfo(std::wstring message);
	void logDebug(std::wstring message);
	void logWarn(std::wstring message);
	void logError(std::wstring message);
	void logFatal(std::wstring message);
	

private:
	Logger(std::string fileName);
	Logger(Logger const&);
	Logger& operator=(Logger const&);
	virtual ~Logger();

	void initialize(std::string fileName);

	src::severity_logger< severity_level > log_;

	static Logger* logger_; // singleton instance
};
}
#endif /* LOGGER_H_ */

