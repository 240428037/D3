priority_queue<int>topK(int *nums, int k){
	//优先级队列：通过堆实现的容器，默认小堆
	priority_queue<int>minQ;
	//堆内只保存k个元素
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