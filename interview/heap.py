# Given k arrays where every array is sorted, create an array which contains
# all elements of k arrays in a sorted fashion

class MinHeap(object):
    def __init__(self):
        self.contents = []

    def _left_child_index(self, index):
        left_child_index = index*2+1
        if left_child_index > (len(self.contents) - 1):
            return None
        return left_child_index

    def _right_child_index(self, index):
        right_child_index = index*2+2
        if right_child_index > (len(self.contents) - 1):
            return None
        return right_child_index

    def _parent_index(self, index):
        parent_index = int((index - 1)/2)
        if parent_index < 0:
            return None
        return parent_index

    def insert(self, elem):
        self.contents.append(elem)
        parent_index = self._parent_index(len(self.contents)-1)
        self.heapify(parent_index)

    def heapify(self, index):
        '''Make heap out of provided index and it's two children.'''
        if index is None:
            return
        left_child_index = self._left_child_index(index)
        right_child_index = self._right_child_index(index)
        if left_child_index and \
                self.contents[left_child_index] < self.contents[index]:
            self.contents[left_child_index], self.contents[index] = \
                    self.contents[index], self.contents[left_child_index]
        if right_child_index and \
                self.contents[right_child_index] < self.contents[index]:
            self.contents[right_child_index], self.contents[index] = \
                    self.contents[index], self.contents[right_child_index]
        parent_index = self._parent_index(index)
        if parent_index:
            self.heapify(parent_index)

    def _verify_heap(self):
        '''Verifies that the heap is correctly built.'''
        for index in range(len(self.contents)):
            left_child_index = self._left_child_index(index)
            right_child_index = self._right_child_index(index)
            if left_child_index and \
                    self.contents[index] > self.contents[left_child_index]:
                return False
            if right_child_index and \
                    self.contents[index] > self.contents[right_child_index]:
                return False
        return True

if __name__ == '__main__':
    heap = MinHeap()
    heap.insert(4)
    heap.insert(7)
    heap.insert(1)
    heap.insert(3)
    heap.insert(2)
    heap.insert(5)
    heap.insert(6)
    heap.insert(9)
    heap.insert(8)
    heap.insert(10)
    print('Heap is: {}'.format(str(heap.contents)))
    assert True == heap._verify_heap()
    heap = MinHeap()
    heap.insert(1)
    heap.insert(2)
    heap.insert(3)
    heap.insert(4)
    heap.insert(5)
    heap.insert(6)
    heap.insert(7)
    heap.insert(8)
    heap.insert(9)
    heap.insert(10)
    print('Heap is: {}'.format(str(heap.contents)))
    assert True == heap._verify_heap()
