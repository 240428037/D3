class Solution {
public:
	void adjustdown(vector<int>&nums, int n, int root){
		int parent = root;
		int child = parent * 2 + 1;
		while (child<n){
			//ѡ�����Һ����нϴ����һ��
			if (child + 1 < n&&nums[child + 1] > nums[child]){
				child++;
			}
			//������ӱȸ��״󣬽������������µ���
			if (nums[child]>nums[parent]){
				swap(nums[child], nums[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else{
				//�������С�ڸ��ף����������
				break;
			}
		}
	}
	void heapsort(vector<int>&nums){
		int n = nums.size();
		//����-�ӵ�����һ����Ҷ�ӽڵ��������ʼ������һֱ���������ڵ�������Ϳ��Ե��ɶ�-adjustdown
		//��������-�����
		for (int i = (n - 1 - 1) / 2; i >= 0; i--){
			adjustdown(nums, n, i);
		}
		//�������ѵ���
		for (int end = n - 1; end >= 0; end--){
			//����-�ѵ�ǰ�����������������
			swap(nums[0], nums[end]);
			//����-�ҳ���ǰ����������
			adjustdown(nums, end, 0);
		}
	}
	vector<int> sortArray(vector<int>& nums) {
		heapsort(nums);
		return nums;
	}
};