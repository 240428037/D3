priority_queue<int>topK(int *nums, int k){
	//���ȼ����У�ͨ����ʵ�ֵ�������Ĭ��С��
	priority_queue<int>minQ;
	//����ֻ����k��Ԫ��
	for (int num : nums){
		if (minQ.size()<k || num>minQ.top()){
			minQ.push(num);
		}
		if (minQ.size() > k){
			minQ.pop();
		}
	}
	return minQ;
}
vector<int>findTopKLargest(int[]nums, int k){
	priority_queue<int>mQ = topK(nums, k);
	vector<int>lst;
	while (!mQ.empty()){
		lst.push_back(mQ.top();
		mQ.pop();
	}
	return lst;
}