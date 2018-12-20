
#ifndef _BRKS_INTF_CONSISTENCY_HASH_CLUSTER_H
#define _BRKS_INTF_CONSISTENCY_HASH_CLUSTER_H

#include <map>
#include <string>
#include <unistd.h>
#include <map>

#include "glo_def.h"

class consistency_hash_cluster_t
{
public:
	consistency_hash_cluster_t();
    ~consistency_hash_cluster_t();
    pid_t get(const std::string& key);   // ��ȡkey�ڻ��ϵ�����Ľ���ID
    void delete_node(const pid_t key);
    void add_node(const pid_t key);

private:
    std::map<u64, pid_t> server_nodes_; //����ڵ�,key�ǹ�ϣֵ��value�ǽ���ID
    const u64 virtual_node_num_ = 512; //ÿ�����̽ڵ����������ڵ����
    const u64 seed_ = 0x1234ABCD;
};


#endif

