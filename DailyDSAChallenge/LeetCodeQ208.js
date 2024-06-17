/**
 * LeetCode Q.208 - "Implement Trie (Prefix Tree)"
 * Link: https://leetcode.com/problems/implement-trie-prefix-tree/description/
 * Twitter Article with detailed explanation: https://x.com/compose/articles/edit/1802029108253048832
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
 * There are various applications of this data structure, such as autocomplete and spellchecker.
 * 
 * Implement the Trie class:
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 */

class TrieNode {
    constructor() {
        this.children = {};
        this.endOfWord = false;
    }
}

class Trie {
    constructor() {
        this.root = new TrieNode();
    }

    insert(word) {
        let node = this.root;
        for(let char of word) {
            if(!node.children[char]) {
                node.children[char] = new TrieNode();
            }
            node = node.children[char];
        }
        node.endOfWord = true;
    }

    search(word) {
        let node = this._searchNode(word);
        return node != null && node.endOfWord;
    }

    startsWith(word) {
        let node = this._searchNode(word);
        return node != null;
    }

    _searchNode(word) {
        let node = this.root;
        for(let char of word) {
            if(!node.children[char]) {
                return null;
            }
            node = node.children[char];
        }

        return node;
    }
}