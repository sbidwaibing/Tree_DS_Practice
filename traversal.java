class node
{
    int data;
    node left,right;
    public node(int value)
    {
        data = value;
        left = right = null;
    }
}

public class traversal {
    public static void main(String args[]){

        node root = new node(1);
        root.left = new node(2);
        root.right = new node(3);

        root.left.left = new node(4);
        root.left.right = new node(5);

        root.right.left = new node(6);
        root.right.right = new node(7);

        traversal t1 = new traversal();
        
        System.out.print("\nInOrder Data Traversal   :");
        t1.inOrder(root);
        
        System.out.print("\nPreOrder Data Traversal  :");
        t1.preOrder(root);
        
        System.out.print("\nPostOrder Data Traversal :");
        t1.postOrder(root);

        System.out.println();
    }

    public void inOrder(node root)
    {
        if(root == null) return;
        inOrder(root.left);
        System.out.print(root.data);
        inOrder(root.right);
    }

    public void preOrder(node root)
    {
        if(root == null) return;
        System.out.print(root.data);
        preOrder(root.left);
        preOrder(root.right);
    }
    public void postOrder(node root)
    {
        if(root == null) return;
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.data);
    }
}
