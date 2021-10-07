import * as functions from 'firebase-functions';
import * as admin from 'firebase-admin';

admin.initializeApp();
const db = admin.firestore();
const fcm = admin.messaging();

// export const sendToMessages = functions.firestore
//     .document('messages/messageId')
//     .onCreate(async snapshot => {
//         const message = snapshot.data();

//         const payload: admin.messaging.MessagingPayload = {
//             notification: {
//                 title: 'New message from user',
//                 body: message.messageBody
//             }
//         }
//         fcm.sendToTopic('messages', payload);

//     });


export const notifyNewMessage = functions.firestore
    .document('messages/{messageId}')
    .onCreate(async snapshot => {
        const message = snapshot.data();

        const querySnapshot = await db
            .collection('users')
            .doc(message.receiverId)
            .collection('tokens')
            .get();

        const tokens = querySnapshot.docs.map(snap => snap.id);

        const payload: admin.messaging.MessagingPayload = {
            notification: {
                title: `Flutter Chat App | ${message.senderName}`,
                body: message.messageBody,
                clickAction: 'FLUTTER_NOTIFICATION_CLICK',
            }
        }
        return fcm.sendToDevice(tokens, payload);

    });



// // Start writing Firebase Functions
// // https://firebase.google.com/docs/functions/typescript
//
// export const helloWorld = functions.https.onRequest((request, response) => {
//   functions.logger.info("Hello logs!", {structuredData: true});
//   response.send("Hello from Firebase!");
// });
