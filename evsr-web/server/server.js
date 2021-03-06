import express from 'express';
import bodyParse from 'body-parser';
import cors from 'cors';
import * as path from 'path';
import logger from './util/Logger';
import { createServer } from 'http';
import { listenToSockets } from './service/sockets';

const app = express();
const router = express.Router();

app.use(router); 
app.use(express.static(path.join(__dirname, '/../client/build')));
app.use(express.static(path.join(__dirname, '/../presentation')));
 

app.use(
  '*',
  cors({
    origin: 'http://localhost:3000',
  }),
);

// Set up routes

router.get('/', function (req, res) { 
  logger.info("Requesting: /") 
  res.redirect('/app')
});


router.get('/presentation', (req, res) => {
  logger.info("Requesting: /presentation")
  res.sendFile(path.join(__dirname + '/../presentation/index.html'));
});

router.get('/app*', (req, res) => {
  logger.info("Requesting: /app*")
  res.sendFile(path.join(__dirname + '/../client/build/index.html'));
});


// Set up socket.io
var http = createServer(app);
listenToSockets(http);
http.listen(process.env.PORT || 8080);

logger.info('Server running and listening on port 8080 ...');
