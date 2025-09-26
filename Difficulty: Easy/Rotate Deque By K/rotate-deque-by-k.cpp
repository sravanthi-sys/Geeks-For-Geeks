class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        k %= dq.size();
        if(type == 1){
            while(k --){
                int num = dq.back();
                dq.pop_back();
                dq.push_front(num);
            }
        }
        if(type == 2){
            while(k --){
                int num = dq.front();
                dq.pop_front();
                dq.push_back(num);
            }
        }
    }
};