# Strivers-A2Z-Sheet

This Repository contain the codes that I have done while following the Strivers A2Z DSA Course.

To create multiple folders at once I used below command in powershell

$folders = @(
    "Lec1 - Traversals",
    "Lec2 - Medium Problems",
    "Lec3 - Hard Problems"
)
$folders | ForEach-Object { New-Item -ItemType Directory -Name $_ }

To create to multiple files with .cpp extension use below command

$files = @(
     "Height of a Binary Tree",
     "Check if the Binary tree is height-balanced or not",
     "Diameter of Binary Tree",
     "Maximum path sum",
     "Check if two trees are identical or not",
     "Zig Zag Traversal of Binary Tree",
     "Boundary Traversal of Binary Tree",
     "Vertical Order Traversal of Binary Tree",
     "Top View of Binary Tree",
     "Bottom View of Binary Tree",
     "Right/Left View of Binary Tree",
     "Symmetric Binary Tree"
 )
$files | ForEach-Object { New-Item -ItemType File -Name "$_.cpp" -Force }

For running a file, first go to that directory then add the main function accordingly and then run below command from terminal

g++ "Height of a Binary Tree.cpp" -o height

then run 

./height.exe