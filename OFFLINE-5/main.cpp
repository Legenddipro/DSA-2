#include "b1.cpp"
int main()
{
    Bst b;
    Node *root = NULL;

   ifstream in("input.txt");
  
   string line;
   while (getline(in, line)) {
        char operation;
        int key = -1; // Initialize key to a value indicating it's not applicable.

        // Extract the operation type (first character) from the line.
        operation = line[0];

        // If the operation has an associated key (integer value), extract it.
         // Convert the substring to an integer.


        // Process the extracted operation and key.
        switch (operation) {
            case 'I':
                //out << "Insert: "  << endl;

            key = stoi(line.substr(2));
                root = b.insert(root,key);
                out<<"(";
                b.show(root);
                out<<")";
                out<<endl;
                // Insert the key into the Binary Search Tree (BST).
                // Code to insert the key into BST can be added here.
                break;
            case 'D':
             key = stoi(line.substr(2));
               // out << "Delete: "  << endl;
               if(b.search(root,key))
               {
                 root = b.deleteBst(root,key);
               }
                   out<<"(";
                b.show(root);
                out<<")";
                out<<endl;
                // Delete the key from the Binary Search Tree (BST).
                // Code to delete the key from BST can be added here.
                break;
            case 'T':
               // out << "Traversal: " << endl;
                if(line.substr(2) == "In")
                {
                    b.inorder(root);
                    out<<endl;
                }
                else  if(line.substr(2) == "Pre")
                {
                    b.preorder(root);
                    out<<endl;
                }
                else  if(line.substr(2) == "Post")
                {
                    b.postorder(root);
                    out<<endl;
                }
                // Perform the specified traversal (In-order, Pre-order, Post-order).
                // Code to perform the traversal on BST can be added here.
                break;
            case 'F':
             key = stoi(line.substr(2));
               // out << "Find: "  << endl;
                if(b.search(root,key))
                {
        out<<"found"<<endl;
     }
     else
     {
        out<<"not found"<<endl;
     }
                // Search for the key in the Binary Search Tree (BST).
                // Code to find the key in BST can be added here.
                break;
            default:
                out << "Invalid operation: " << operation << endl;
                break;
        }
    }
    

    in.close();
    return 0;

 
}
