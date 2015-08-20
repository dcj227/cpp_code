/***********************************************************************
 * Author :          dingchangjiang
 * Email :           dcj227@163.com
 * Last modified :   2015-08-16 00:02
 * Filename :        multi_thread_redis_access.hpp
 * Description :     
 * *********************************************************************/

#ifndef MULTI_THREAD_REDIS_ACCESS_H
#define MULTI_THREAD_REDIS_ACCESS_H

#include <string>

#include <hiredis.h>

namespace mredis {

enum MREDIS_T {
  MR_SUCCESS = 0
}

class RedisAccess {
 public:
  RedisAccess();

  // connect
  MREDIS_T initialize(
      const std::string& host,
      const int port,
      const int timeout,
      const std::sting& passwd,
      const int db_);

 private:
  std::string     redis_host_;
  int             port_;
  int             timeout_;
  std::string     password_;
  int             db_;
};


}  // namespace multiredis

#endif  // MULTI_THREAD_REDIS_ACCESS_H
