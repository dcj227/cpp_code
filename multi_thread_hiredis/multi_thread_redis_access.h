/***********************************************************************
 * Author :          dingchangjiang
 * Email :           dcj227@163.com
 * Last modified :   2015-08-16 00:02
 * Filename :        multi_thread_redis_access.h
 * Description :     wrap hiredis to support multi process access, and provide
 *                   simple interface to get and set.
 * *********************************************************************/

#ifndef MULTI_THREAD_REDIS_ACCESS_H
#define MULTI_THREAD_REDIS_ACCESS_H

#include <string>
#include <vector>

#include <boost/pthread.h>
#include <hiredis.h>

namespace mhiredis {

enum MHIREDIS_T {
  MH_SUCCESS = 0,
  MH_NOT_INIT
}

class MHiRedis {
 public:
  /* constructor */
  MHiRedis();

  /* destructor */
  ~MHiRedis();

  /*
   * describe: initialize MHiRedis's members and connect to redis server.
   * parameters:
   *        host:     redis server's host address or ip address.
   *        port:     redis server's port num.
   *        passwd:   redis server's password.
   *        db:       db num in redis server to select.
   *        timeout:  connection timeout.
   *        is_non_block:   set connection's block flag.
   * return:
   *        refference to MHIREDIS_T enum.
   */
  MHIREDIS_T initialize(
      const std::string& host, const int port, const std::sting& passwd,
      const int db, const int timeout, const bool is_non_block);

  /*
   * describe: free redis resource and close connection.
   * parameters:
   * return:
   *        refference to MHIREDIS_T enum.
   */
  MHIREDIS_T cleanUp();

  /*
   * describe: get a string reply from redis server.
   * parameters:
   *        command:  command to execute.
   *        reply:    reply string from redis server.
   * return:
   *        refference to MHIREDIS_T enum.
   */
  MHIREDIS_T getString(const std::sting& command, std::string* reply_str);

  /*
   * describe: get array replys from redis server.
   * parameters:
   *        command:    command to execute.
   *        reply_list: reply array from redis server.
   * return:
   *        refference to MHIREDIS_T enum. 
   */
  MHIREDIS_T getArray(const std::string& command,
                      std::vector<std::string>* reply_list);

  /*
   * describe: execute a non get command to redis server.
   * parameters:
   *        command:    command to execute.
   *        reply_intager:  reply from redis server.
   * return:
   *        refference to MHIREDIS_T enum.
   */
  MHIREDIS_T execCommand(const std::string& command, long long* reply_intager);

  /*
   * describe: execute multi command atomic.
   * parameters:
   *        commands:   commands to execute.
   *        reply_list: 
   *        reply_intager:
   * return:
   *        refference to MHIREDIS_T enum.
   */
  MHIREDIS_T execCommands(
      const std::vector<std::string>& commands,
      std::vector<std::string>* reply_list, long long* reply_intager);
  
 private:
  std::string     host_;
  int             port_;
  int             timeout_;
  std::string     password_;
  int             db_;

  redisContext*   context_;
  boost::mutex    context_mutex_;
};

}  // namespace multiredis

#endif  // MULTI_THREAD_REDIS_ACCESS_H
