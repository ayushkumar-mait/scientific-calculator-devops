# -------- Stage 1: Build --------
FROM gcc:13 AS builder

WORKDIR /app

COPY src/calculator.cpp .

RUN g++ calculator.cpp -o calculator


# -------- Stage 2: Runtime --------
FROM debian:bookworm-slim

WORKDIR /app

COPY --from=builder /app/calculator .

CMD ["./calculator"]
