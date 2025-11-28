/* tree.h */
#define _GNU_SOURCE

#include <stdio.h>  
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>
#include <errno.h>

#define TagRood 1 /* 00 01 */
#define TagNode 2 /* 00 10 */
#define TagLeaf 4 /* 01 00 */

typedef unsigned int int32;
typedef signed short int16;
typedef unsigned char int8;
typedef unsigned char Tag;

struct s_node {
    Tag tag;
    struct s_node *north; // =up if at the top root, returns itself
    struct s_node *west; // =left 
    struct s_leaf *east; // =right (右には実際に値をもたせる)

    int8 path[256]; // ルートからのpath情報を全て持っておく
};

typedef struct s_node Node;

struct s_leaf {
    union u_tree *west;
    struct s_leaf *east;
    int8 key[128];
    int8 *value;
    int16 size;
};  

typedef struct s_leaf Leaf;

union u_tree {
    Node n;
    Leaf l;
};
typedef union u_tree Tree;