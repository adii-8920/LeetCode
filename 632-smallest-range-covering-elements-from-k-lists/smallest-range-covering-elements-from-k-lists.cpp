class Node{
    public:
    int data;
    int row;
    int col; 

    Node(int data, int row, int col){//Constructor
        this->data= data;
        this->row= row;
        this->col= col;
    }

};

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        int maxi= INT_MIN;
        int mini= INT_MAX;
        int k= nums.size();

        //step1: create a min Heap for starting element of each list and tracking mini/maxi value
        for(int i= 0; i< k; i++){
            int element= nums[i][0];
            mini= min(mini, element);
            maxi= max(maxi, element);

            minHeap.push(new Node(element, i, 0));//starting element daal diya har list ka
        }
        int start= mini, end= maxi;

        while(minHeap.size() >0){
            Node* temp= minHeap.top();
            minHeap.pop();

            mini= temp->data;//mini update kar diya(mini ki value badhate ja rahe h jisse range kam hoti jaaye)

            //Ab ans(diff/range) update karenge
            if(maxi - mini < end - start){
                start = mini;
                end= maxi;
            }

            //Ab maxi update karenge()
            if(temp->col+ 1 < nums[temp->row].size()){//next element ka index n se kam hona chahiye
                maxi= max(maxi, nums[temp->row][temp->col + 1]);
                minHeap.push(new Node(nums[temp->row][temp->col + 1], temp->row, temp->col + 1));
            }
            else{//if list is exhausted(iske aage kuch exist nahi karta )
                break;
            }
            
        }
        return {start, end};//C++ me {start, end} likhne par compiler automatically 2 elements (start aur end) ka vector<int> bana kar return kar deta hai (ise initializer list kehte hain).
        }
};