#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Combatant {
    string name;
    int hp;
    int attack;
    int id;

    Combatant() {}
    Combatant(string n, int h, int a, int i) {
        name = n;
        hp = h;
        attack = a;
        id = i;
    }
};

struct Node {
    Combatant data;
    Node* left;
    Node* right;

    Node(Combatant c) {
        data = c;
        left = right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, Combatant c) {
        if (node == NULL)
            return new Node(c);
        if (c.id < node->data.id)
            node->left = insert(node->left, c);
        else if (c.id > node->data.id)
            node->right = insert(node->right, c);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int id) {
        if (node == NULL)
            return node;
        if (id < node->data.id)
            node->left = deleteNode(node->left, id);
        else if (id > node->data.id)
            node->right = deleteNode(node->right, id);
        else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            } else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data.id);
        }
        return node;
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data.name << "(" << node->data.hp << " HP)  ";
            inorder(node->right);
        }
    }

    void clear(Node* node) {
        if (node != NULL) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    BST() { root = NULL; }
    ~BST() { clear(root); }

    void insert(Combatant c) { root = insert(root, c); }

    void deleteCombatant(int id) { root = deleteNode(root, id); }

    Node* getFrontline() {
        return findMin(root);
    }

    void displayTeam() {
        inorder(root);
        cout << endl;
    }

    bool isEmpty() { return root == NULL; }
};

int randomDamage(int baseAttack) {
    return baseAttack + (rand() % 5);
}

void printTeamStatus(BST& player, BST& enemy, int round) {
    cout << "\n================ Round " << round << " ================\n";
    cout << "\nHeroes: ";
    player.displayTeam();
    cout << "Enemies: ";
    enemy.displayTeam();
    cout << "-------------------------------------------\n";
}

int main() {
    srand(time(0));

    BST playerTeam, enemyTeam;

    playerTeam.insert(Combatant("Hero_A", 30, 6, 1));
    playerTeam.insert(Combatant("Hero_B", 25, 8, 2));
    playerTeam.insert(Combatant("Hero_C", 28, 7, 3));
    playerTeam.insert(Combatant("Hero_D", 20, 9, 4));
    playerTeam.insert(Combatant("Hero_E", 32, 5, 5));

    enemyTeam.insert(Combatant("Enemy_X", 30, 6, 11));
    enemyTeam.insert(Combatant("Enemy_Y", 25, 7, 12));
    enemyTeam.insert(Combatant("Enemy_Z", 28, 8, 13));
    enemyTeam.insert(Combatant("Enemy_M", 22, 10, 14));
    enemyTeam.insert(Combatant("Enemy_N", 26, 9, 15));

    int round = 1;

    cout << "===== Welcome to BattleQuest: BST Arena =====\n";

    while (!playerTeam.isEmpty() && !enemyTeam.isEmpty()) {
        printTeamStatus(playerTeam, enemyTeam, round);

        Node* playerFront = playerTeam.getFrontline();
        Node* enemyFront = enemyTeam.getFrontline();

        if (playerFront == NULL || enemyFront == NULL)
            break;

        cout << "\n⚔️  " << playerFront->data.name << " attacks " << enemyFront->data.name << "!\n";
        int dmg = randomDamage(playerFront->data.attack);
        enemyFront->data.hp -= dmg;
        cout << "Damage dealt: " << dmg << "\n";
        if (enemyFront->data.hp <= 0) {
            cout << enemyFront->data.name << " is defeated!\n";
            enemyTeam.deleteCombatant(enemyFront->data.id);
        }

        if (enemyTeam.isEmpty()) break;

        enemyFront = enemyTeam.getFrontline();
        playerFront = playerTeam.getFrontline();

        cout << "\n🛡️  " << enemyFront->data.name << " attacks " << playerFront->data.name << "!\n";
        dmg = randomDamage(enemyFront->data.attack);
        playerFront->data.hp -= dmg;
        cout << "Damage dealt: " << dmg << "\n";
        if (playerFront->data.hp <= 0) {
            cout << playerFront->data.name << " is defeated!\n";
            playerTeam.deleteCombatant(playerFront->data.id);
        }

        round++;
    }

    if (playerTeam.isEmpty() && enemyTeam.isEmpty())
        cout << "The battle ends in a draw!\n";
    else if (enemyTeam.isEmpty())
        cout << "🏆 Player’s team wins the BattleQuest!\n";
    else
        cout << "💀 Enemy team wins the BattleQuest!\n";

    return 0;
}
