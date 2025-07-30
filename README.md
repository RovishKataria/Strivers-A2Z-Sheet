# Strivers-A2Z-Sheet

This Repository contain the codes that I have done while doing the Strivers A2Z DSA Course.

- To create multiple folders at once I used below command in powershell
```
$folders = @(
    "Lec1 - Traversals",
    "Lec2 - Medium Problems",
    "Lec3 - Hard Problems"
)
$folders | ForEach-Object { New-Item -ItemType Directory -Name $_ }
```

- To create to multiple files with .cpp extension use below command
```
$path = "Step 13 - Binary Trees\Lec3 - Hard Problems"

$files = @(
    "Root to Node Path in Binary Tree",
    "LCA in Binary Tree",
    "Maximum width of a Binary Tree",
    "Check for Children Sum Property",
    "Print all the Nodes at a distance of K in a Binary Tree",
    "Minimum time taken to BURN the Binary Tree from a Node",
    "Count total Nodes in a COMPLETE Binary Tree",
    "Requirements needed to construct a Unique Binary Tree | Theory",
    "Construct Binary Tree from inorder and preorder",
    "Construct the Binary Tree from Postorder and Inorder Traversal",
    "Serialize and deserialize Binary Tree",
    "Morris Preorder Traversal of a Binary Tree",
    "Morris Inorder Traversal of a Binary Tree",
    "Flatten Binary Tree to LinkedList"
)

if (!(Test-Path $path)) { New-Item -ItemType Directory -Path $path -Force }

$files | ForEach-Object { New-Item -ItemType File -Path "$path\$_.cpp" -Force }
```

- For running a file, first go to that directory then add the main function accordingly and then run below command from terminal
```
g++ "Height of a Binary Tree.cpp" -o height

then run 

./height.exe
```
OR
- Use coderunner extension in vscode

Suggestions:
1. Before doing Greedy (Step 12), do Graphs (Step 15) and Dynamic Programming (Step 16).
2. Do Binary Trees (Step 13) and Binary Search Trees (Step 14) together.
