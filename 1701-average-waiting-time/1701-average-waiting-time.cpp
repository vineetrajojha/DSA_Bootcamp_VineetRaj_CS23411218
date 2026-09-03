class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
         int i =0;
        double wait =0;
        int cus = customers.size();
        int getfood =customers[0][0];
        while(i!=cus){
           if(getfood> customers[i][0]){
           getfood =  customers[i][1] + getfood;
           wait = wait + getfood - customers[i][0];
           }
           else{
            getfood = customers[i][0]+customers[i][1];
            wait = wait +customers[i][1];
           }
           i++;
        }
        return wait/cus;
        
    }
};