#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Letters
{
public:
	char letter;
	float probability;
	string code;
	Letters() {
		letter = '\0';
		probability = 0.0;
		code = "";
	}
	Letters(char c, float pb) {
		letter = c;
		probability = pb;
		code = "";
	}
};

class letterNode {
public:
	float totalProbability = 0.0;
	vector<Letters> nodes;
	letterNode() {}

	letterNode(float prob, Letters letter) {
		totalProbability = prob;
		nodes.push_back(letter);
	}
};

bool compareByProbability(const letterNode& a, const letterNode& b) {
	return a.totalProbability < b.totalProbability;
}

void huffman(vector<letterNode>&letters) {
	while (letters.size() > 1) {
		letterNode combined;
		// Combine the two lowest probability nodes
		combined.totalProbability = letters[0].totalProbability + letters[1].totalProbability;

		// Assign '0' to the first node
		for (int i = 0; i < letters[0].nodes.size(); i++) {
			letters[0].nodes[i].code = "0" + letters[0].nodes[i].code;
			combined.nodes.push_back(letters[0].nodes[i]);
		}

		// Assign '1' to the second node
		for (int j = 0; j < letters[1].nodes.size(); j++) {
			letters[1].nodes[j].code = "1" + letters[1].nodes[j].code;
			combined.nodes.push_back(letters[1].nodes[j]);
		}

		letters.erase(letters.begin(), letters.begin() + 2);
		letters.push_back(combined);
		std::sort(letters.begin(), letters.end(), compareByProbability);
	}
}

int main() {
	float check = 0;
    int n;
    cout << "Please enter the number of letters to Encode: \n";
    cin >> n;

    vector<letterNode> huff;
    char letter;
    float pb;

    for (int i = 1; i <= n; ++i) {
        cout << "Please enter the letter number \"" << i << "\" and its probability: ";
        cin >> letter >> pb;
		check += pb;
        // Create a new letter and its node
        Letters newLetter(letter, pb);
        huff.push_back(letterNode(pb, newLetter));
    }
	if (check != 1.0) {
		cout << "Wrong probabilities, the summation of probabilities sould equal 1.\n";
		return 1;
	}
    // Sort the vector by initial probabilities
    sort(huff.begin(), huff.end(), compareByProbability);

    // Perform Huffman encoding
    huffman(huff);

    // Display the results
    for (const auto& node : huff[0].nodes) {
        cout << "The letter '" << node.letter << "' with probability " << node.probability
             << " has the code: " << node.code << "\n";
    }

    return 0;
}