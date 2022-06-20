# 二叉树

## defination

1. 深度 depth(v)
   由树的连通性,每一节点与根之间都有一条路径相联;而根据树的无环性,由根通往每个节点的路径必然唯一。
   沿每个节点v到根r的唯一通路所经过边的数目,称作v的深度(depth)
   根节点的深度depth(r) = 0,故属于第0层

2. 祖先和后代
   ancestor, descendant
   proper ancestor, proper descendant
   parent, child

3. 度 deg(v)
   v的孩子总数,称作其度数或度(degree)
   无孩子的节点称作叶节点(leaf)

4. 子树 subtree(v)
   v所有的后代及其之间的联边称作子树(subtree)
   
5. 高度 height(T)
   树T中所有节点深度的最大值称作该树的高度(height)
   全树的高度亦即其根节点r的高度,height(T) = height(r)

## 多叉树(k-ary tree)
1. 父节点表示法 (images/1.png)
   仅需常数时间,即可确定任一节点的父节点
   孩子节点的查找却不得不花费O(n)时间访遍所有节点
2. 子节点表示法 (images/2.png)
   对于拥有r个孩子的节点,可在O(r + 1)时间内列举出其所有的孩子
3. 父节点+子节点表示法 (images/3.png)
   各节点既记录父节点,同时也维护一个序列以保存所有孩子
4. 有序多叉树 = 二叉树
   
## 编码树

## 遍历(images/4.png)
1. 先序遍历(images/5.png)
   
2. 中序遍历(images/6.png)
   
3. 后序遍历(images/7.png)
   
4. 层次遍历
   
