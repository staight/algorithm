/*
124. Binary Tree Maximum Path Sum

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6

Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxPathSum(root *TreeNode) int {
	res := math.MinInt64
	helper(root, &res)
	return res
}

func helper(root *TreeNode, sum *int) int {
	if root == nil {
		return 0
	}
	left := max(0, helper(root.Left, sum))
	right := max(0, helper(root.Right, sum))
	*sum = max(*sum, left+right+root.Val)
	return max(left, right) + root.Val
}