#!/bin/bash

logger "Message"
logger -p local0.info "Message"
logger -s -p local0.info "Message"
logger -t myscript -p local0.info "Message"
logger -i -t myscript "Message"
