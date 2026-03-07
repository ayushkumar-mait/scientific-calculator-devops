FROM gcc:latest

WORKDIR /app

COPY src/calculator.cpp .

RUN g++ calculator.cpp -o calculator

CMD ["./calculator"]
