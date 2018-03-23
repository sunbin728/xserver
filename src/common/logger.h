#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>
#include <mutex>
#include <sys/time.h>
#include <iostream>
#include <sstream>
#include <fstream>
/*
#define LOG(str) \
    Logger::Instance().Log(INFO, __FILE__, __LINE__, str)

#define LOGDEBUG(str) \
    Logger::Instance().Log(DEBUG, __FILE__, __LINE__, str)

#define LOGINFO(str) \
    Logger::Instance().Log(INFO, __FILE__, __LINE__, str)

#define LOGWARN(str) \
    Logger::Instance().Log(WARN, __FILE__, __LINE__, str)

#define LOGERROR(str) \
    Logger::Instance().Log(ERROR, __FILE__, __LINE__, str)

#define LOGCRITICAL(str) \
    Logger::Instance().Log(CRITICAL, __FILE__, __LINE__, str)

#define LOGFATAL(str) \
    Logger::Instance().Log(FATAL, __FILE__, __LINE__, str)

#define LOG_DEBUG(str, ...) \
    Logger::Instance().Log(LOG_LEVEL::DEBUG, __FILE__, __LINE__, str, __VA_ARGS__)

#define LOG_INFO(str, ...) \
    Logger::Instance().Log(LOG_LEVEL::INFO, __FILE__, __LINE__, str, __VA_ARGS__)

#define LOG_WARN(str, ...) \
    Logger::Instance().Log(LOG_LEVEL::WARN, __FILE__, __LINE__, str, __VA_ARGS__)

#define LOG_ERROR(str, ...) \
    Logger::Instance().Log(LOG_LEVEL::ERROR, __FILE__, __LINE__, str, __VA_ARGS__)

#define LOG_CRITICAL(str, ...) \
    Logger::Instance().Log(LOG_LEVEL::CRITICAL, __FILE__, __LINE__, str, __VA_ARGS__)

#define LOG_FATAL(str, ...) \
    Logger::Instance().Log(LOG_LEVEL::FATAL, __FILE__, __LINE__, str, __VA_ARGS__)
*/

#define LOG(...) \
    Logger::Instance().Log(LOG_LEVEL::INFO, __FILE__, __LINE__, __VA_ARGS__)

#define LOG_DEBUG(...) \
    Logger::Instance().Log(LOG_LEVEL::DEBUG, __FILE__, __LINE__, __VA_ARGS__)

#define LOG_INFO(...) \
    Logger::Instance().Log(LOG_LEVEL::INFO, __FILE__, __LINE__, __VA_ARGS__)

#define LOG_WARN(...) \
    Logger::Instance().Log(LOG_LEVEL::WARN, __FILE__, __LINE__, __VA_ARGS__)

#define LOG_ERROR(...) \
    Logger::Instance().Log(LOG_LEVEL::ERROR, __FILE__, __LINE__, __VA_ARGS__)

#define LOG_CRITICAL(...) \
    Logger::Instance().Log(LOG_LEVEL::CRITICAL, __FILE__, __LINE__, __VA_ARGS__)

#define LOG_FATAL(...) \
    Logger::Instance().Log(LOG_LEVEL::FATAL, __FILE__, __LINE__, __VA_ARGS__)

enum LOG_LEVEL
{
    DEBUG=1, //1
    INFO,     //2
    WARN,   //3
    ERROR,   //4
    CRITICAL,
    FATAL,
    DISABLE = 100
};

class Logger{
    private:
        Logger():
            m_toConsole(true),
            m_toFile(true),
            m_logName("log"),
            m_level(LOG_LEVEL::INFO){
            };
        Logger(Logger &logger);
        Logger& operator=(Logger &logger);
        ~Logger(){
            if (m_file.is_open()){
                m_file.flush();
                m_file.close();
            }
        };

    public:
        static Logger& Instance();

        void TimerFlush();

        void Init(std::string logName, LOG_LEVEL level, bool toFile=true);

        void Log(LOG_LEVEL level, std::string filename, int lineno, const char *fmt, ...);

        void SetLogName(std::string logName){
            m_logName = logName;
        }

        void SetLevel(LOG_LEVEL level){
            m_level = level;
        }

        void SetToFile(bool toFile){
            m_toFile = toFile;
        }

        void Flush(){
            std::lock_guard<std::mutex> mtx_locker(m_mtx);
            if (m_file.is_open()){
                m_file.flush();
            }
        }

    private:
        //std::string getTime()
        //{
            //time_t timep;
            //time (&timep);
            //char tmp[64];
            //strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep) );
            //return tmp;
        //}

        std::string getTime()
        {
             struct timeval tv;
             gettimeofday(&tv,NULL);
             struct tm* pTime;
             pTime = localtime(&tv.tv_sec);
             char sTemp[30] = {0};
             snprintf(sTemp, sizeof(sTemp), "%04d-%02d-%02d %02d:%02d:%02d.%d", pTime->tm_year+1900, \
                                 pTime->tm_mon+1, pTime->tm_mday, pTime->tm_hour, pTime->tm_min, pTime->tm_sec, \
                                             (int)tv.tv_usec);
             return (std::string)sTemp;
        }

        std::string format_head(LOG_LEVEL level, std::string filename, int lineno){
            int iIndex = filename.rfind("/");
            std::string shortFileName = filename.substr(++iIndex);
            std::ostringstream   ostr;
            ostr << shortLevel(level) <<  getTime() << " " << shortFileName << ":" << lineno << "] ";
            return ostr.str();
        }

        std::string shortLevel(LOG_LEVEL level);

        void write(std::string& strlog);

        std::string getFileName(){
            time_t timep;
            time (&timep);
            char tmp[64];
            strftime(tmp, sizeof(tmp), "%Y%m%d",localtime(&timep) );
            std::ostringstream   ostr;
            ostr << m_logName << "-" << tmp << ".log";
            return ostr.str();
        }

    private:
        bool m_toConsole;
        bool m_toFile;
        std::string m_logName;
        LOG_LEVEL m_level;
        std::ofstream m_file;
        std::string m_fileName;
        std::mutex m_mtx;
        bool m_flushTimer;
};

#endif /* _LOGGER_H_ */
