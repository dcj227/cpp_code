/***********************************************************************
 * Author :          dingchangjiang
 * Email :           dcj227@163.com
 * Last modified :   2015-08-19 23:35
 * Filename :        multi_thread_redis_access.cpp
 * Description :     
 * *********************************************************************/

#include "multi_thread_redis_access.h"

#include <boost/smart_ptr.hpp>

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
      
  MHIREDIS_T ret = connect(host_ip_, port_, passwd_, db_);
  return ret;
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

MHIREDIS_T MHiRedis::getItem(
    const std::string& command, std::string* reply_str) {
  if (!reply_str) {
    return MH_PARAMETER_ERROR;
  }

  if (!context_) {
    return MH_NOT_INIT;
  }

  MHIREDIS_T ret = MH_SUCCESS;
  redisReply* reply = NULL;
  boost::shared_ptr<redisReply> tmp((void*)NULL, freeReplyObject);

  ret = doCommand(command, &reply);
  if (ret != MH_SUCCESS) {
    return ret;
  }

  if (reply && reply->str) {
    (*reply_str).assign(reply->str, reply->len);
  }
  
  return MH_SUCCESS;
}

MHIREDIS_T MHiRedis::getArray(
    const std::string& command, std::vector<std::string>* reply_list) {
  if (!reply_list) {
    return MH_PARAMETER_ERROR;
  }

  if (!context_) {
    return MH_NOT_INIT;
  }

  MHIREDIS_T ret = MH_SUCCESS;
  redisReply* reply = NULL;
  boost::shared_ptr<redisReply> tmp((void*)NULL, freeReplyObject);

  ret = doCommand(command, &reply);
  if (ret != MH_SUCCESS) {
    return ret;
  }

  if (reply->type != REDIS_REPLY_ARRAY) {
    return; 
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

MHIREDIS_T MHiRedis::connect(const std::string& host, const int port,
                             const std::sting& password, const int db) {
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
  if (!passwork.emply()) {
    std::string auth_comm = "AUTH " + password;
    MHIREDIS_T ret = execCommand(auth_comm, NULL);
    if (ret != MH_SUCCESS) {
      return MH_AUTH_FAILED;
    }
  }

  std::string sel_comm = "SELECT " + itoa(db);
  ret = execCommand(sel_comm, NULL);
  if (ret != MH_SUCCESS) {
    return MH_SEL_FAILED;
  }

  return MH_SUCCESS;
}

MHIREDIS_T MHiRedis::command(const std::string& command, redisReply* reply) {
}

MHIREDIS_T MHiRedis::commands(const std::vector<std::string>& commands,
                              redisReply* reply) {


}

}  // namespace mredis
