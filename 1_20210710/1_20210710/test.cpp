class Solution {
public:
	void adjustdown(vector<int>&nums, int n, int root){
		int parent = root;
		int child = parent * 2 + 1;
		while (child<n){
			//选出左右孩子中较大的那一个
			if (child + 1 < n&&nums[child + 1] > nums[child]){
				child++;
			}
			//如果孩子比父亲大，交换，继续向下调整
			if (nums[child]>nums[parent]){
				swap(nums[child], nums[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else{
				//如果孩子小于父亲，则调整结束
				break;
			}
		}
	}
	void heapsort(vector<int>&nums){
		int n = nums.size();
		//建堆-从倒数第一个非叶子节点的子树开始调整，一直调整到根节点的树，就可以调成堆-adjustdown
		//堆排升序-建大堆
		for (int i = (n - 1 - 1) / 2; i >= 0; i--){
			adjustdown(nums, n, i);
		}
		//交换调堆迭代
		for (int end = n - 1; end >= 0; end--){
			//交换-把当前最大的数交换到最后面
			swap(nums[0], nums[end]);
			//调堆-找出当前数当中最大的
			adjustdown(nums, end, 0);
		}
	}
	vector<int> sortArray(vector<int>& nums) {
		heapsort(nums);
		return nums;
	}
};