/***********************************************************************
 * Author :          dingchangjiang
 * Email :           dcj227@163.com
 * Last modified :   2015-08-19 23:35
 * Filename :        multi_thread_redis_access.cpp
 * Description :     
 * *********************************************************************/

#include "multi_thread_redis_access.h"

namespace mredis {

MHiRedis::MHiRedis() : context_(NULL) , host_(""), port_(0), password_(""), 
      db_(-1) {
}

MHiRedis::~MHiRedis() {
}

MHIREDIS_T MHiRedis::initialize(const std::string& host_ip, const int port,
                                const std::sting& password, const int db) {
  host_ip_ = host_ip;
  port_ = port;
  passwd_ = password;
  db_ = db;
      
  context_ = redisConnect(host_ip_.c_str(), port_);

  if (!context_) {
    cleanUp();
    return MH_CONNECT_RET_NULL;
  }

  if (context_->err != 0) {
    // log errstr

    cleanUp();
    return MH_CONNECT_ERROR;
  } 

  return MH_SUCCESS;
}

MHIREDIS_T MHiRedis::cleanUp() {
  // free redis resource
  redisFree(context_);

  // reset members
  context_  = NULL;
  host_     = "";
  port_     = 0;
  password_ = "";
  db_       = -1;
  timeout_  = 0;
}

MHIREDIS_T MHiRedis::getString(
    const std::string& command, std::string* reply_str) {
  if (!context_) {
    return MH_NOT_INIT;
  }

  return MH_SUCCESS;
}

MHIREDIS_T MHiRedis::getArray(
    const std::string& command, std::vector<std::string>* reply_list) {
  if (!context_) {
    return MH_NOT_INIT;
  }
  return MH_SUCCESS;
}

MHIREDIS_T MHiRedis::execCommand(
    const std::string& command, long long* reply_intager) {
  if (!context_) {
    return MH_NOT_INIT;
  }
  return MH_SUCCESS;
}

MHIREDIS_T MHiRedis::execCommands(
      const std::vector<std::string>& commands,
      std::vector<std::string>* reply_list, long long* reply_intager) {
  if (!context_) {
    return MH_NOT_INIT;
  }
  return MH_SUCCESS;
}

}  // namespace mredis
