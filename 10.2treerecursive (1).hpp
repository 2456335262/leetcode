#include <iostream>
 
typedef int tree_t;
 
struct TreeNode{
    tree_t val;
    TreeNode* left;
    TreeNode* right;
};
 
TreeNode* cons_tree(tree_t e, TreeNode* l, TreeNode* r){
    TreeNode* tmp;
    tmp = new TreeNode;
    tmp->val = e;
    tmp->left = l;
    tmp->right = r;
    return tmp;
}

TreeNode* ordered_insertion_tree(tree_t e, TreeNode* t){
    if(t == NULL){
        return cons_tree(e, NULL, NULL);
    }
    else if(e < t->val){
        t->left = ordered_insertion_tree(e, t->left);
        return t;
    }
    else{
        t->right = ordered_insertion_tree(e, t->right);
        return t;
    }
}
 
void print_tree(TreeNode* t){
    if(t != NULL){
        print_tree(t->left);
        std::cout << t->val << std::endl;
        print_tree(t->right);
    }
}
 
void deallocate_tree(TreeNode* t){
    if(t != NULL){
        deallocate_tree(t->left);
        deallocate_tree(t->right);
        delete t;
    }
}
 
/*bool search_ordered_tree(tree_t e, TreeNode* t){
    if(t == NULL){
        return false;
    }
    if(e == t->val){
        return true;
        }
        else if(e < t->val){

            return search_ordered_tree(e, t->left);
        }
        else{
            return search_ordered_tree(e, t->right);
        }
}*/
bool search_ordered_tree(tree_t e, TreeNode* t){
  bool found = false;
    if(t != NULL){
        found = search_ordered_tree(e, t->left);
        //std::cout << "current node"<< t->val << std::endl;
        if(e == t->val || found )
          return true;
        found = search_ordered_tree(e, t->right);
        if(found)
          return true;
    }
    return false;
}
    



int count_occurrences_tree(tree_t e, TreeNode* t) {
    

    if(t!=NULL){
        if (t->val==e){
            return 1+count_occurrences_tree(e, t->right);
    }
    else if( e > t->val){
    
        return count_occurrences_tree(e, t-> right);
    }
    else if( e < t->val){
      
        return count_occurrences_tree(e, t->left);
    }
  }
  return 0;
  

    
    
}

TreeNode* min_element_tree(TreeNode* t){

    if(t == NULL){
        return NULL;
    }
    if(t->left == NULL){
        return t;
    }
    else{
        return min_element_tree(t->left);
    }
}

int count_nodes_tree(TreeNode* t){
    
    if(t == NULL){
        return 0;
    }
    else{
        return 1 + count_nodes_tree(t->left) + count_nodes_tree(t->right);
    }
}

int count_leaves_tree(TreeNode* t){
  if(t==NULL){
      return 0;
      }
  else if(t->left == NULL && t->right == NULL){
      return  1;
      }
  else{
      return  count_leaves_tree(t->right)+count_leaves_tree(t->left);
      }
  }


int main(){
    TreeNode* t;
    t = NULL;
 
    t = ordered_insertion_tree(15, t);
    t = ordered_insertion_tree(4, t);
    t = ordered_insertion_tree(6, t);
    t = ordered_insertion_tree(1, t);
    t = ordered_insertion_tree(4, t);
    t = ordered_insertion_tree(18, t);
    t = ordered_insertion_tree(9, t);
 

    print_tree(t);


    std::cout << search_ordered_tree(4, t) << std::endl;
    /*std::cout << count_occurrences_tree(4, t) << std::endl;
    std::cout << min_element_tree(t)->val << std::endl << std::endl;
    std::cout << count_nodes_tree(t) << std::endl;
    std::cout << count_leaves_tree(t) << std::endl;*/

 
    deallocate_tree(t);
 
}
