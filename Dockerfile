FROM gcc:13 AS builder

WORKDIR /app
COPY src/calculator.cpp .

RUN g++ calculator.cpp -o calculator

FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y libstdc++6

WORKDIR /app
COPY --from=builder /app/calculator .

CMD ["./calculator"]
