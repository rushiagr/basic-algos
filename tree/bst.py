class TreeNode(object):
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def bst_insert(root, val):
    '''Insert value into BST. Note if value is already present, we're not
    inserting.  Note that below crisp code handles all cases.'''
    if root is None:
        return TreeNode(val)
    if val < root.val:
        root.left = bst_insert(root.left, val)
    elif val > root.val:
        root.right = bst_insert(root.right, val)
    return root

def bst_lowest(root):
    '''Find lowest value in BST'''
    if root is None:
        return
    curr = root
    while curr.left is not None:
        curr = curr.left
    return curr

def bst_highest(root):
    '''Find highest value in BST'''
    if root is None:
        return
    curr = root
    while curr.right is not None:
        curr = curr.right
    return curr

def bst_remove(root, val):
    '''Remove value from BST. The function returns value of the node which will
    replace current (i.e. root) node.'''
    if root is None:
        return None
    if root.val < val:
        root.right = bst_remove(root.right, val)
    elif root.val > val:
        root.left = bst_remove(root.left, val)
    else:
        if root.left is None:
            root = root.right
        elif root.right is None:
            root = root.left
        else:
            temp = bst_highest(root.left)
            root.val = temp.val
            root.left = bst_remove(root.left, temp.val)
    return root

def bst_print_inorder(root):
    if root is None:
        return
    bst_print_inorder(root.left)
    print(root.val)
    bst_print_inorder(root.right)

if __name__ == '__main__':
    root = TreeNode(50)
    bst_insert(root, 30)
    bst_insert(root, 20)
    bst_insert(root, 40)
    bst_insert(root, 70)
    bst_insert(root, 60)
    bst_insert(root, 80)
    bst_print_inorder(root)
    bst_remove(root, 50)
    print('=======')
    bst_print_inorder(root)
    print(root.val)
    print('done')
