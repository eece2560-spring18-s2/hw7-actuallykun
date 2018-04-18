#include "member.h"
#include <list> 

#include <queue>

#include "database.h"

namespace algdb {

void Member::DumpConnections() {
  std::cout << "(" << member_id << ")";
  for (auto &m : connecting_members) {
    auto conn = m.second;
    std::cout << "->" << conn.dst->member_id << 
      "(" << conn.group->group_id << ")";
  }
  std::cout << "\n";
}

void Member::PathToMemberBFS(uint64_t dst_member_id) {
  color = COLOR_GRAY;
  std::list<Member *> queue;
  queue.push_back(this);
  while(!queue.empty()) {
    Member *u = queue.front();
    queue.pop_front();
    for(auto v : u->connecting_members){
      std::cout << v.second.dst;
      if(v.second.dst->color == COLOR_WHITE){
        v.second.dst->color = COLOR_GRAY;
        v.second.dst->parent = u;
        if (v.second.dst->member_id != dst_member_id){
          queue.push_back(v.second.dst);
        }
        else {
          return;
        }
      }
    }
    u->color = COLOR_BLACK;
  }
}

bool Member::DLS(Member *src, uint64_t target, int limit){
  if (src->member_id == target){
    return true;
  }
  if (limit <= 0){
    return false;
  }
  for (auto i : src->connecting_members){
    
    if (DLS(i.second.dst, target, limit - 1) == true){
      i.second.dst->parent = src;
      return true;
    }
  }
  return false;
}

void Member::PathToMemberIDDFS(uint64_t dst_member_id) {
  // Fill in your code here
  int max_depth = connecting_members.size();
  for (int i = 0; i <= max_depth; i++){
    if (DLS(this, dst_member_id, i) == true){
      break;
    }
  }
}
  
void Member::PrintPath(Member* dst) {
  Member *curr = dst;
  while(curr && curr != this) {
    std::cout << curr->member_name << " <- ";
    curr = curr->parent;
  }
  std::cout << this->member_name << "\n";
}

}
