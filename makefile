CXX = g++
CXXFLAGS = -std=c++11 -Wall
     
OBJS = main.o Matrix.o NeuralNetwork.o Detector.o

langDetector : ${OBJS}
	${CXX} $(CXXFLAGS) -o $@ ${OBJS}

clean :
	rm ${OBJS} langDetector


