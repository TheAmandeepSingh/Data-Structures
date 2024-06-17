/**
 * LeetCode Q.208 - "Implement Trie (Prefix Tree)"
 * Link: https://leetcode.com/problems/replace-words/description/
 * Twitter Article with detailed explanation: https://x.com/amandeepgini/status/1802408302820704580
 *
 * In English, we have a concept called root, which can be followed by some other word to form another longer word -
 * let's call this word derivative. For example, when the root "help" is followed by the word "ful",
 * we can form a derivative "helpful".Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces,
 * replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root,
 * replace it with the root that has the shortest length.Return the sentence after the replacement.
 * 
 * Example 1:
 * Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
 * Output: "the cat was rat by the bat"
 * 
 * Example 2:
 * Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
 * Output: "a a b c"
 */

/**
 * Simple solution
 * @param {*} dictionary 
 * @param {*} sentence 
 * @returns 
 */
function replaceWords(dictionary, sentence) {
    const dict = new Set(dictionary);
    const words = sentence.split(' ');

    for(let i = 0; i < words.length; i++) {
        for(let j = 1; j < words[i].length; j++) {
            const prefix = words[i].substring(0, j);
            if(dict.has(prefix)) {
                words[i] = prefix;
                break;
            }
        }
    }

    return words.join(' ');
}

/**
 * Using Trie
 */
}
class TrieNode {
    constructor() {
        this.children = {};
        this.endOfWord = false;
    }
}

function buildTrie(dictionary) {
    const root = new TrieNode();
    for (const word of dictionary) {
        let node = root;
        for (let char of word) {
            if (!node.children[char]) {
                node.children[char] = new TrieNode();
            }
            node = node.children[char];
        }
        node.endOfWord = true;
    }
    return root;
}

function replaceWordsUsingTrie(dictionary, sentence) {
    const root = buildTrie(dictionary);
    const words = sentence.split(' ');

    const replaceWords = (word) => {
        let node = root;
        let prefix = '';
        for (let char of word) {
            if (!node.children[char]) {
                break;
            }
            node = node.children[char];
            prefix += char;
            if (node.endOfWord) {
                return prefix;
            }
        }
        return word;
    };

    for (let i = 0; i < words.length; i++) {
        words[i] = replaceWords(words[i]);
    }

    return words.join(' ');
}
