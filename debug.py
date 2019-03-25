from a5 import *

##################################################
#                 Debug Class
#
# This is for you to check if your entropy, information gain, and classify implementations produce the
# intended results. Further debugging should be done on your own, and the grading tool will provide feedback
# as to what you might be missing.
#
# Simply run the main function at the bottom of the file to check your results compared to the intended answers.
#
##################################################

class debug:
    def __init__(self):
        self.classifications = [1, 1, 1, 2, 2, 2, 2, 2]
        self.test_node = Node(3,{'money': Node(None, {}, 0), 'size': Node(2,
                                                               {'color': Node(None, {}, 1), 'length': Node(1,
                                                                                                   {'weight': Node(None, {}, 0), 'width': Node(None, {}, 1)})})}, None)


    def debug_entropy(self):
        test1 = [self.classifications[i] for i in (0, 1, 3)]
        entropy_test = get_entropy(test1)
        print(entropy_test)

        test2 = [self.classifications[i] for i in [2, 4, 5, 6, 7]]
        entropy_test = get_entropy(test2)
        print(entropy_test)

        test3 = [self.classifications[i] for i in list(range(8))]
        entropy_test = get_entropy(test3)
        print(entropy_test)

    def debug_informationGain(self):
        parent_classifications = self.classifications
        child1_classifications = [self.classifications[i] for i in (0, 1, 3)]
        child2_classifications = [self.classifications[i] for i in [2, 4, 5, 6, 7]]
        ig_test = get_information_gain(parent_classifications, {1:child1_classifications, 2:child2_classifications}, {1:3, 2:5})
        print(ig_test)

    def debug_classify(self):
       test_point_1 = {1:'b', 2:'color', 3:'money'}
       classification_test_1 = self.test_node.classify(test_point_1)
       print(classification_test_1)
       test_point_2 = {1: 'width', 2: 'length', 3: 'size'}
       classification_test_2 = self.test_node.classify(test_point_2)
       print(classification_test_2)
       test_point_3 = {1: 'weight', 2: 'color', 3: 'size'}
       classification_test_3 = self.test_node.classify(test_point_3)
       print(classification_test_3)


if __name__ == '__main__':
    d = debug()
    print("\nYour entropy values: ")
    d.debug_entropy()
    print("\nExpected entropy values: \n0.9182958340544896\n0.7219280948873623\n0.954434002924965")
    print("\nYour information gain value: ")
    d.debug_informationGain()
    print("\nExpected information gain value: \n0.15886800584993")
    print("\nYour classify values: ")
    d.debug_classify()
    print("\nExpected classify values: \n0 \n1 \n1")
