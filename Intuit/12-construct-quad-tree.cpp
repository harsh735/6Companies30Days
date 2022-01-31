/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    Node* construct(vector<vector<int>>& grid) {
	    int r = grid.size();
	    int c = grid[0].size();		
        
	    if (r == 0) return nullptr;
		return solve(0, 0, r, c, grid);
    }   

    Node* solve(int r1, int c1, int r2, int c2, vector<vector<int>>& grid) {
	
        int val = grid[r1][c1];
	    for (int r = r1; r < r2; r++) {
		    for (int c = c1; c < c2; c++) {
			    if (grid[r][c] != val) {
				    int r_mid = r1 + (r2 - r1) / 2;
				    int c_mid = c1 + (c2 - c1) / 2;

				    Node* node = new Node();
                    node->val = 0;
				    node->isLeaf = false;
				    node->topLeft = solve(r1, c1, r_mid, c_mid, grid);
				    node->topRight = solve(r1, c_mid, r_mid, c2, grid);
				    node->bottomLeft = solve(r_mid, c1, r2, c_mid, grid);
				    node->bottomRight = solve(r_mid, c_mid, r2, c2, grid);
				    return node;
			    }
		    }
	    }
	    return new Node(grid[r1][c1] != 0, true, nullptr, nullptr, nullptr, nullptr);
    }
};