const express = require('express');

const EID_TARGET = new Date('2026-03-20T17:00:00.000Z');
const PORT = process.env.PORT ?? 3000;

const app = express();

app.disable('x-powered-by');
app.use(express.json());

function getCountdown(from, to) {
    const totalMs = Math.max(0, to.getTime() - from.getTime());
    const totalSeconds = Math.floor(totalMs / 1000);
    const seconds = totalSeconds % 60;
    const minutes = Math.floor(totalSeconds / 60) % 60;
    const hours = Math.floor(totalSeconds / 3600) % 24;
    const days = Math.floor(totalSeconds / 86400);
    return { days, hours, minutes, seconds, totalSeconds };
}

function jsonResponse(res, data, statusCode = 200, meta = {}) {
    const payload = {
        success: statusCode >= 200 && statusCode < 300,
        data,
    };
    return res.status(statusCode).json(payload);
}

app.get('/', (req, res) => {
    const now = new Date();
    const isPast = now >= EID_TARGET;
    const countdown = isPast
        ? { days: 0, hours: 0, minutes: 0, seconds: 0, totalSeconds: 0 }
        : getCountdown(now, EID_TARGET);

    return jsonResponse(res, {
        event: 'Eid al-Fitr 1447 H',
        target: EID_TARGET.toISOString(),
        targetFormatted: '21 Maret 2026',
        isPast,
        countdown,
        message: isPast
            ? 'Eid Mubarak! Idul Fitri telah tiba.'
            : `${countdown.days} hari, ${countdown.hours} jam, ${countdown.minutes} menit, ${countdown.seconds} detik menuju Idul Fitri.`,
    });
});

app.get('/countdown', (req, res) => {
    res.redirect(302, '/');
});

app.get('/health', (req, res) => {
    return jsonResponse(res, { status: 'ok' });
});

app.use((req, res) => {
    return jsonResponse(
        res,
        { error: 'Not Found', path: req.path },
        404,
        { code: 'NOT_FOUND' }
    );
});

app.use((err, req, res, next) => {
    console.error(err);
    return jsonResponse(
        res,
        { error: 'Internal Server Error' },
        500,
        { code: 'INTERNAL_ERROR' }
    );
});

app.listen(PORT, () => {
    console.log(`Eid countdown API listening on http://localhost:${PORT}`);
});
