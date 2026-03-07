FROM gcc:13 AS builder

WORKDIR /app
COPY src/calculator.cpp .

# compile static binary
RUN g++ -static calculator.cpp -o calculator

FROM debian:bookworm-slim

WORKDIR /app
COPY --from=builder /app/calculator .

CMD ["./calculator"]
