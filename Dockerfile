FROM alpine:latest as exercice_TP2

WORKDIR jeu-de-la-vie

RUN apk update --no-cache && \
 apk add git gcc make ncurses-dev ncurses-static build-base && \
 git clone https://github.com/Dam2Gs/jeu-de-la-vie.git . && \
 mkdir -p bin && \
 make

FROM alpine:latest

LABEL org.opencontainers.image.authors="Damien" \
 org.opencontainers.image.date="2023-09-20T15:41:00"

RUN apk update && apk add ncurses-dev ncurses-static

COPY --from=exercice_TP2 /jeu-de-la-vie/bin/jeuDeLaVie /jeuDeLaVie

RUN adduser -g "Damien SSI" -D -H -s /bin/nologin damien

USER damien

ENTRYPOINT ["./jeuDeLaVie"]
CMD ["15", "15", "40", "5"]