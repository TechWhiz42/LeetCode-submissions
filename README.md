# LeetCode-submissions
A collection of LeetCode questions to ace the coding interview! - Created using [LeetHub v2](https://github.com/arunbhardwaj/LeetHub-2.0)

<------------------------------------------------------------------------------------------------>
flowchart TD

subgraph group_docs["Documentation"]
  node_root_readme["README<br/>catalog index<br/>[README.md]"]
  node_stats_json["Stats<br/>progress metadata<br/>[stats.json]"]
end

subgraph group_automation["Automation"]
  node_sync_workflow["Sync LeetCode<br/>github workflow<br/>[sync_leetcode.yml]"]
end

subgraph group_arrays["Array / Math"]
  node_p0001["Two Sum<br/>problem module"]
  node_p0015["3Sum<br/>problem module"]
  node_p0238["Product Except<br/>problem module"]
  node_p0347["Top K<br/>problem module"]
end

subgraph group_lists["Linked Structures"]
  node_p0019["Remove Nth<br/>problem module"]
  node_p0023["Merge K Lists<br/>problem module"]
  node_p0143["Reorder List<br/>problem module"]
end

subgraph group_trees["Trees"]
  node_p0094["Inorder<br/>problem module"]
  node_p0105["Build Tree<br/>problem module"]
  node_p0236["LCA Tree<br/>problem module"]
end

subgraph group_graphs["Graphs"]
  node_p0200["Islands<br/>problem module"]
  node_p2582["Min Score Path<br/>problem module"]
  node_p2914["Safest Path<br/>problem module"]
end

subgraph group_strings["Strings / Design"]
  node_p0208["Trie<br/>problem module"]
  node_p0211["Word Search<br/>problem module"]
  node_p1122["Dup Substring<br/>problem module"]
end

node_sync_workflow -->|"syncs"| node_p0001
node_sync_workflow -->|"syncs"| node_p0023
node_sync_workflow -->|"syncs"| node_p0208
node_sync_workflow -->|"updates"| node_stats_json
node_sync_workflow -->|"refreshes"| node_root_readme
node_root_readme -->|"indexes"| node_p0001
node_root_readme -->|"indexes"| node_p0015
node_root_readme -->|"indexes"| node_p0238
node_root_readme -->|"indexes"| node_p0094
node_root_readme -->|"indexes"| node_p0200
node_root_readme -->|"indexes"| node_p0208
node_root_readme -->|"indexes"| node_p2582
node_root_readme -->|"indexes"| node_p2914
node_stats_json -->|"summarizes"| node_root_readme
node_p0208 -->|"same pattern"| node_p0211
node_p0094 -->|"same pattern"| node_p0105
node_p0200 -->|"same pattern"| node_p2914

click node_root_readme "https://github.com/techwhiz42/leetcode-submissions/blob/main/README.md"
click node_stats_json "https://github.com/techwhiz42/leetcode-submissions/blob/main/stats.json"
click node_sync_workflow "https://github.com/techwhiz42/leetcode-submissions/blob/main/.github/workflows/sync_leetcode.yml"
click node_p0001 "https://github.com/techwhiz42/leetcode-submissions/tree/main/0001-two-sum"
click node_p0015 "https://github.com/techwhiz42/leetcode-submissions/tree/main/0015-3sum"
click node_p0238 "https://github.com/techwhiz42/leetcode-submissions/tree/main/0238-product-of-array-except-self"
click node_p0347 "https://github.com/techwhiz42/leetcode-submissions/tree/main/0347-top-k-frequent-elements"
click node_p0019 "https://github.com/techwhiz42/leetcode-submissions/tree/main/0019-remove-nth-node-from-end-of-list"
click node_p0023 "https://github.com/techwhiz42/leetcode-submissions/tree/main/0023-merge-k-sorted-lists"
click node_p0143 "https://github.com/techwhiz42/leetcode-submissions/tree/main/0143-reorder-list"
click node_p0094 "https://github.com/techwhiz42/leetcode-submissions/tree/main/0094-binary-tree-inorder-traversal"
click node_p0105 "https://github.com/techwhiz42/leetcode-submissions/tree/main/0105-construct-binary-tree-from-preorder-and-inorder-traversal"
click node_p0236 "https://github.com/techwhiz42/leetcode-submissions/tree/main/0236-lowest-common-ancestor-of-a-binary-tree"
click node_p0200 "https://github.com/techwhiz42/leetcode-submissions/tree/main/0200-number-of-islands"
click node_p0208 "https://github.com/techwhiz42/leetcode-submissions/tree/main/0208-implement-trie-prefix-tree"
click node_p0211 "https://github.com/techwhiz42/leetcode-submissions/tree/main/0211-design-add-and-search-words-data-structure"
click node_p1122 "https://github.com/techwhiz42/leetcode-submissions/tree/main/1122-longest-duplicate-substring"
click node_p2582 "https://github.com/techwhiz42/leetcode-submissions/tree/main/2582-minimum-score-of-a-path-between-two-cities"
click node_p2914 "https://github.com/techwhiz42/leetcode-submissions/tree/main/2914-find-the-safest-path-in-a-grid"

classDef toneNeutral fill:#f8fafc,stroke:#334155,stroke-width:1.5px,color:#0f172a
classDef toneBlue fill:#dbeafe,stroke:#2563eb,stroke-width:1.5px,color:#172554
classDef toneAmber fill:#fef3c7,stroke:#d97706,stroke-width:1.5px,color:#78350f
classDef toneMint fill:#dcfce7,stroke:#16a34a,stroke-width:1.5px,color:#14532d
classDef toneRose fill:#ffe4e6,stroke:#e11d48,stroke-width:1.5px,color:#881337
classDef toneIndigo fill:#e0e7ff,stroke:#4f46e5,stroke-width:1.5px,color:#312e81
classDef toneTeal fill:#ccfbf1,stroke:#0f766e,stroke-width:1.5px,color:#134e4a
class node_root_readme,node_stats_json,node_p0208,node_p0211,node_p1122 toneBlue
class node_sync_workflow toneAmber
class node_p0001,node_p0015,node_p0238,node_p0347 toneMint
class node_p0019,node_p0023,node_p0143 toneRose
class node_p0094,node_p0105,node_p0236 toneIndigo
class node_p0200,node_p2582,node_p2914 toneTeal
<------------------------------------------------------------------------------------------------>

<!---LeetCode Topics Start-->
# LeetCode Topics
## Array
|  |
| ------- |
| [0001-two-sum](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0001-two-sum) |
| [0081-search-in-rotated-sorted-array-ii](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0081-search-in-rotated-sorted-array-ii) |
| [1288-remove-covered-intervals](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/1288-remove-covered-intervals) |
| [1301-number-of-paths-with-max-score](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/1301-number-of-paths-with-max-score) |
| [1331-rank-transform-of-an-array](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/1331-rank-transform-of-an-array) |
## Hash Table
|  |
| ------- |
| [0001-two-sum](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0001-two-sum) |
| [0208-implement-trie-prefix-tree](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0208-implement-trie-prefix-tree) |
| [1331-rank-transform-of-an-array](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/1331-rank-transform-of-an-array) |
## Dynamic Programming
|  |
| ------- |
| [0124-binary-tree-maximum-path-sum](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0124-binary-tree-maximum-path-sum) |
| [1301-number-of-paths-with-max-score](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/1301-number-of-paths-with-max-score) |
## Matrix
|  |
| ------- |
| [1301-number-of-paths-with-max-score](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/1301-number-of-paths-with-max-score) |
## Sorting
|  |
| ------- |
| [1288-remove-covered-intervals](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/1288-remove-covered-intervals) |
| [1331-rank-transform-of-an-array](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/1331-rank-transform-of-an-array) |
## Math
|  |
| ------- |
| [3754-concatenate-non-zero-digits-and-multiply-by-sum-i](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/3754-concatenate-non-zero-digits-and-multiply-by-sum-i) |
| [3756-concatenate-non-zero-digits-and-multiply-by-sum-ii](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/3756-concatenate-non-zero-digits-and-multiply-by-sum-ii) |
## String
|  |
| ------- |
| [0208-implement-trie-prefix-tree](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0208-implement-trie-prefix-tree) |
| [0211-design-add-and-search-words-data-structure](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0211-design-add-and-search-words-data-structure) |
| [3756-concatenate-non-zero-digits-and-multiply-by-sum-ii](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/3756-concatenate-non-zero-digits-and-multiply-by-sum-ii) |
## Prefix Sum
|  |
| ------- |
| [3756-concatenate-non-zero-digits-and-multiply-by-sum-ii](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/3756-concatenate-non-zero-digits-and-multiply-by-sum-ii) |
## Linked List
|  |
| ------- |
| [0023-merge-k-sorted-lists](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0023-merge-k-sorted-lists) |
| [0143-reorder-list](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0143-reorder-list) |
## Two Pointers
|  |
| ------- |
| [0143-reorder-list](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0143-reorder-list) |
## Stack
|  |
| ------- |
| [0143-reorder-list](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0143-reorder-list) |
## Recursion
|  |
| ------- |
| [0143-reorder-list](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0143-reorder-list) |
## Divide and Conquer
|  |
| ------- |
| [0023-merge-k-sorted-lists](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0023-merge-k-sorted-lists) |
## Heap (Priority Queue)
|  |
| ------- |
| [0023-merge-k-sorted-lists](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0023-merge-k-sorted-lists) |
## Merge Sort
|  |
| ------- |
| [0023-merge-k-sorted-lists](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0023-merge-k-sorted-lists) |
## Binary Search
|  |
| ------- |
| [0081-search-in-rotated-sorted-array-ii](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0081-search-in-rotated-sorted-array-ii) |
## Tree
|  |
| ------- |
| [0124-binary-tree-maximum-path-sum](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0124-binary-tree-maximum-path-sum) |
| [0572-subtree-of-another-tree](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0572-subtree-of-another-tree) |
## Depth-First Search
|  |
| ------- |
| [0124-binary-tree-maximum-path-sum](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0124-binary-tree-maximum-path-sum) |
| [0211-design-add-and-search-words-data-structure](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0211-design-add-and-search-words-data-structure) |
| [0572-subtree-of-another-tree](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0572-subtree-of-another-tree) |
| [2685-count-the-number-of-complete-components](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/2685-count-the-number-of-complete-components) |
## String Matching
|  |
| ------- |
| [0572-subtree-of-another-tree](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0572-subtree-of-another-tree) |
## Binary Tree
|  |
| ------- |
| [0124-binary-tree-maximum-path-sum](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0124-binary-tree-maximum-path-sum) |
| [0572-subtree-of-another-tree](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0572-subtree-of-another-tree) |
## Hash Function
|  |
| ------- |
| [0572-subtree-of-another-tree](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0572-subtree-of-another-tree) |
## Breadth-First Search
|  |
| ------- |
| [2685-count-the-number-of-complete-components](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/2685-count-the-number-of-complete-components) |
## Union-Find
|  |
| ------- |
| [2685-count-the-number-of-complete-components](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/2685-count-the-number-of-complete-components) |
## Graph Theory
|  |
| ------- |
| [2685-count-the-number-of-complete-components](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/2685-count-the-number-of-complete-components) |
## Design
|  |
| ------- |
| [0208-implement-trie-prefix-tree](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0208-implement-trie-prefix-tree) |
| [0211-design-add-and-search-words-data-structure](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0211-design-add-and-search-words-data-structure) |
## Trie
|  |
| ------- |
| [0208-implement-trie-prefix-tree](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0208-implement-trie-prefix-tree) |
| [0211-design-add-and-search-words-data-structure](https://github.com/TechWhiz42/LeetCode-submissions/tree/master/0211-design-add-and-search-words-data-structure) |
<!---LeetCode Topics End-->
