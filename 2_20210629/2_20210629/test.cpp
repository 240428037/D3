class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		int row = board.size();
		int col = board[0].size();
		for (int i = 0; i < row; i++) {
			int sum = 0;
			for (int j = 0; j < col; j++) {
				sum += board[i][j];
			}
			if (sum == col) {
				return true;
			}
		}
		for (int i = 0; i < col; i++) {
			int sum = 0;
			for (int j = 0; j < row; j++) {
				sum += board[j][i];
			}
			if (sum == row) {
				return true;
			}
		}

		int sum = 0;
		for (int i = 0; i < row; i++) {
			sum += board[i][i];
		}
		if (sum == row) return true;
		sum = 0;
		for (int i = 0; i < row; i++) {
			sum += board[i][col - i - 1];
		}
		if (sum == row) return true;
		return false;
	}
};





class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int row = board.size();
		int col = board[0].size();
		//判断行
		for (int i = 0; i < row; i++){
			int sum = 0;
			for (int j = 0; j < col; j++){
				sum += board[i][j];
			}
			if (sum == col){
				return true;
			}
		}
		//判断列
		for (int i = 0; i < col; i++){
			int sum = 0;
			for (int j = 0; j < row; j++){
				//j表示行，i表示列所以board表示为board[j][i]
				sum += board[j][i];
			}
			if (sum == row){
				return true;
			}
		}
		//判断正斜
		int sum = 0;
		for (int i = 0; i < row; i++){
			sum += board[i][i];
		}
		if (sum == row){
			return true;
		}
		//判断副斜
		sum = 0;
		for (int i = 0; i < row; i++){
			sum += board[i][col - 1 - i];
		}
		if (sum == row){
			return true;
		}
		return false;
	}
};