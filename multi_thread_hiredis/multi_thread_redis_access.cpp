/***********************************************************************
 * Author :          dingchangjiang
 * Email :           dcj227@163.com
 * Last modified :   2015-08-19 23:35
 * Filename :        multi_thread_redis_access.cpp
 * Description :     
 * *********************************************************************/

#include "multi_thread_redis_access.h"

namespace mredis {

RedisAccess::RedisAccess() 
    : redis_host_("")
      , port_(0)
      , timeout_(0)
      , password_("")
      , db_(-1) {
}

MREDIS_T RedisAccess::initialize(
    const std::string& host,
    const int port,
    const int timeout,
    const std::sting& passwd,
    const int db_) {
}


}  // namespace mredis
