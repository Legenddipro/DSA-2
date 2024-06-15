void RecursivePrint(Node<T, E> *node, int degree)
    {
        if (node == nullptr)
        {
            return;
        }
        Node<T, E> *temp = node;
        // cout << "(" << node->key << "," << node->value << ")-> ";
        for (int i = 0; i < degree; i++)
        {
            cout << "(" << temp->key << "," << temp->value << ") ";
            temp = temp->right;
        }
        cout << endl;
        temp = node;
        for (int i = 0; i < degree; i++)
        {
            // cout<<"("<<node->key<<","<<node->value<<") ";
            //
            if (temp->Child != nullptr)
            {
                cout << "(" << temp->key << "," << temp->value << ")-> ";
            }

            RecursivePrint(temp->Child, temp->degree);
            temp = temp->right;
        }
        return;
    }