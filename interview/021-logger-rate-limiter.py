# https://tenderleo.gitbooks.io/leetcode-solutions-/content/GoogleEasy/359.html

class Logger(object):
    # key is message, value timestamp
    hmap = {}
    # list of tuples where each tuple is (timestamp, message)
    # better to use deque instead of list
    ls = []
    def can_print_message(self, msg, ts):
        while len(self.ls) and self.ls[0][0] < ts - 10:
            if self.hmap.get(self.ls[0][1]) and self.hmap[self.ls[0][1]] < ts - 10:
                del self.hmap[self.ls[0][1]]
            del self.ls[0]
        self.ls.append((ts, msg))
        if self.hmap.get(msg):
            self.hmap[msg] = ts
            return False
        else:
            self.hmap[msg] = ts
        return True

l = Logger()
print(l.can_print_message('a', 1))
print(l.can_print_message('b', 1))
print(l.can_print_message('a', 4))
print(l.can_print_message('a', 14))
print(l.can_print_message('a', 25))
print(l.can_print_message('b', 15))
