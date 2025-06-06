TEST_SQ = testStackQueue
TEST_FILLS = testFills

OBJS_COLOURPICKERS = stripeColourPicker.o photoNegativeColourPicker.o edgeColourPicker.o solidColourPicker.o
OBJS_MAIN = main.o
OBJS_TEST_FILLS = testFills.o
OBJS_TEST_SQ = testStackQueue.o
OBJS_UTILS  = animation.o lodepng.o RGBAPixel.o PNG.o

INCLUDE_SQ = stack.h queue.h stack.cpp queue.cpp
INCLUDE_FILLS = filler.h filler-private.h filler.cpp stripeColourPicker.h stripeColourPicker-private.h photoNegativeColourPicker.h photoNegativeColourPicker-private.h edgeColourPicker.h edgeColourPicker-private.h solidColourPicker.h
INCLUDE_UTILS = cs221util/PNG.h cs221util/RGBAPixel.h cs221util/lodepng/lodepng.h

CXX = clang++
LD = clang++
CXXFLAGS = -std=c++1y -c -g -O0 -Wall -Wextra -pedantic
LDFLAGS = -std=c++1y -lpthread -lm

all: $(TEST_FILLS) $(TEST_SQ)

$(TEST_SQ) : $(OBJS_TEST_SQ)
	$(LD) $^ $(LDFLAGS) -o $@

$(TEST_FILLS) : $(OBJS_COLOURPICKERS) $(OBJS_TEST_FILLS) $(OBJS_UTILS)
	$(LD) $^ $(LDFLAGS) -o $@

testStackQueue.o : testStackQueue.cpp $(INCLUDE_SQ)
	$(CXX) $(CXXFLAGS) $< -o $@

testFills.o : testFills.cpp $(INCLUDE_FILLS) $(INCLUDE_SQ) $(INCLUDE_UTILS)
	$(CXX) $(CXXFLAGS) $< -o $@

# Pattern rules for object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

PNG.o : cs221util/PNG.cpp $(INCLUDE_UTILS)
	$(CXX) $(CXXFLAGS) $< -o $@

RGBAPixel.o : cs221util/RGBAPixel.cpp $(INCLUDE_UTILS)
	$(CXX) $(CXXFLAGS) $< -o $@

lodepng.o : cs221util/lodepng/lodepng.cpp cs221util/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(TEST_PR) $(TEST_SQ) $(TEST_FILLS) $(OBJS_DIR) *.o frames-output/*.png images-output/*.png images-output/*.gif
